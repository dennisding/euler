
root=$(dirname "$0")

cd "$root/../bin"

emrun --no_browser --no_emrun_detect --port 8080 .
