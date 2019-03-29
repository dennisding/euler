#pragma once

#include "thread.hpp"
#include "singleton.hpp"

#include <list>
#include <thread>
#include <memory>
#include <vector>
#include <functional>

template <typename type>
class thread_task_list
{
	using task_list = std::list<std::function<void()>>;

public:
	std::function<void()> get()
	{
		auto tasks = tasks_.exchange(nullptr);
		while (!tasks) {
			tasks = tasks_.exchange(nullptr);
		}

		if (tasks->empty()) {
			tasks_.exchange(tasks);
			return std::function<void()>(nullptr);
		}

		auto task = *(tasks->begin());
		tasks->pop_front();
		tasks_.exchange(tasks);

		return task;

	}

	static inline thread_task_list &instance()
	{
		static thread_task_list ins_;
		return ins_;
	}

private:
	std::atomic<task_list *> tasks_;
};

template <typename ...types>
struct thread_task
{

};

template <typename head>
struct thread_task<head>
{
	static std::function<void()> get_task()
	{
		return thread_task_list<head>::instance().get();
	}
};

template <typename head, typename ...tails>
struct thread_task<head, tails...>
{
	static std::function<void()> get_task()
	{
		auto task = thread_task_list<head>::instance().get();
		if (task) {
			return task;
		}

		return thread_task<tails...>::get_task();
	}
};

class thread_mgr : public singleton<thread_mgr>
{
	using task_ptr = std::function<void ()>;
	using thread_ptr = std::shared_ptr<std::thread>;
	using thread_vector = std::vector<thread_ptr>;
public:
	thread_mgr() : quit_(false) {}

	void init();

	template <typename type>
	void dispatch(task_ptr task);

	inline bool quit() { return quit_; }
	inline void quit(bool q) { quit_ = q; }

private:
	template <typename ...types>
	static void worker(thread_mgr *mgr)
	{
		while (!mgr->quit()) {
			mgr->execute_one_task<types...>();
		}
	}

	template <typename ...types>
	bool execute_one_task()
	{
		auto task = thread_task<types...>::get_task();
		if (task) {
			task();
			return true;
		}
		return false;
	}

	template <typename ...types>
	void add_worker()
	{
		auto t = std::make_shared<std::thread>(&worker<types...>, this);
		threads_.push_back(t);
	}

private:
	bool quit_;
	thread_vector threads_;
};
