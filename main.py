# Program to unify file names across repo
import os;
import re;

def unify_cpp_file_names(directory,replace_str) : 
    for filename in os.listdir(directory) :
        if not filename.endswith(".cpp") : return

        new_name = filename.lower().replace(".cpp.cpp",".cpp").replace("(works)","").replace(replace_str + "_","")
        print(f"Renaming {filename} to {new_name}")

        current_path = os.path.join(directory,filename)
        new_path = os.path.join(directory,new_name)

        os.rename(current_path, new_path)

if __name__ == "__main__" :
    directory = r"C:\Users\Aarav Aditya Shah\Documents\GitHub\learning-codebases\cpp-learning-codebase\src"
    # Possible options : "strings" , "stack" , "recursion" , "arrays" , "patterns" , "other"
    nested_dir = "other"
    unify_cpp_file_names(os.path.join(directory,nested_dir),"_")