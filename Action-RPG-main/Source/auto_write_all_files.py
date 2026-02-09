import os

# Root directory for scanning
ROOT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.abspath(os.path.join(ROOT_DIR, '..'))

# File extensions to target
TARGET_EXTENSIONS = ['.cpp', '.h', '.cs', '.py', '.md', '.txt', '.ini', '.json', '.mmd']

# Output log file
LOG_FILE = os.path.join(ROOT_DIR, 'auto_write_log.txt')

written_files = []

def auto_write_file(file_path):
    try:
        with open(file_path, 'a', encoding='utf-8') as f:
            f.write('\n// Auto-write marker\n')
        written_files.append(file_path)
    except Exception as e:
        print(f"Failed to write: {file_path} ({e})")

for dirpath, dirnames, filenames in os.walk(PROJECT_ROOT):
    for file in filenames:
        ext = os.path.splitext(file)[1]
        if ext in TARGET_EXTENSIONS:
            file_path = os.path.join(dirpath, file)
            auto_write_file(file_path)

with open(LOG_FILE, 'w', encoding='utf-8') as log:
    for f in written_files:
        log.write(f"{f}\n")

print(f"Auto-write completed for {len(written_files)} files. Log saved to {LOG_FILE}.")

// Auto-write marker
