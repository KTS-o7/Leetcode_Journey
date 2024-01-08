import os
import re

def rename_files():
    for filename in os.listdir('.'):
        if filename.endswith('.cpp'):
            match = re.search(r'Prob(\d+)_', filename)
            if match:
                old_number = match.group(1)
                new_number = old_number.zfill(4)
                new_filename = filename.replace(old_number, new_number)
                os.rename(filename, new_filename)

rename_files()
