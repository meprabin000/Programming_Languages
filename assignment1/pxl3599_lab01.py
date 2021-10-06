""" 
Prabin Lamichhane
1001733599
OS - Windows (tested on omega)
"""
import os

def dir_size(path):
    size = 0
    all_dirs = os.listdir( path ) # access the path, and store the subdirectories in all_dir
    for i_dir in all_dirs: 
        run_dir = os.path.join(path, i_dir) # creating the path to the sub-directory using root directory path
        if os.path.isfile(run_dir): # check if it is a file 
            size += os.path.getsize(run_dir) # get the size of the file and add it to size
        else:
            size += dir_size(run_dir) # else, loop over the files inside subdirectory using recursive function
    return size #return the size at the end

def main():
    print(dir_size("."))

if __name__ == "__main__":
    main()
    