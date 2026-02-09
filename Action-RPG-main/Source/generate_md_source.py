import os

# Root directory containing .md files
ROOT_DIR = os.path.dirname(os.path.abspath(__file__))

# Output directory for generated source code files
OUTPUT_DIR = os.path.join(ROOT_DIR, 'GeneratedSource')

if not os.path.exists(OUTPUT_DIR):
    os.makedirs(OUTPUT_DIR)

def generate_source_from_md(md_path, output_dir):
    with open(md_path, 'r', encoding='utf-8') as f:
        content = f.read()
    # Simple conversion: wrap content in a C++ comment block
    filename = os.path.splitext(os.path.basename(md_path))[0] + '.cpp'
    output_path = os.path.join(output_dir, filename)
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write('/*\n' + content + '\n*/\n')
    print(f"Generated: {output_path}")

# Recursively scan all subdirectories for .md files
PROJECT_ROOT = os.path.abspath(os.path.join(ROOT_DIR, '..'))
for dirpath, dirnames, filenames in os.walk(PROJECT_ROOT):
    for file in filenames:
        if file.endswith('.md'):
            md_path = os.path.join(dirpath, file)
            generate_source_from_md(md_path, OUTPUT_DIR)

print("All .md files recursively converted to C++ source code comments.")
// Auto-write marker
