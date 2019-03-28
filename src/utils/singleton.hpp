#pragma once

template <typename type>
class singleton
{
	singleton(const singleton &) = delete;
	void operator=(const singleton &) = delete;

protected:
	singleton() {}

public:
	static type &instance()
	{
		static type ins_;

		return ins_;
	}
};
