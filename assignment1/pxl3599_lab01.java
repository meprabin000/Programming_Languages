/* 
Prabin Lamichhane
1001733599
OS - Windows (tested on omega)
*/
import java.io.File;


public class pxl3599_lab01 {
    // function that gives the size of the directory
    public static long get_dirsize( File dir ) {
        long size = 0;
        File[] all_dir = dir.listFiles(); // list all subdirectories and files inside the main directory
        int dirCount = all_dir.length; // get the count of subdirectories

        for( int i = 0; i < dirCount; i++ ) // loop over all subdirectories
        {
            if( all_dir[i].isFile() ) // check if the subdirectory is a file
            {
                size += all_dir[i].length(); // if yes, get the size of the file
            }
            else // if it is a sub-directory, get the size of the directory by recursively calling this method
            {
                size += get_dirsize( all_dir[i] );
            }
        }
        return size; // return the size of the actual directory
    }
    public static void main(String[] args)
    {
        String dir_name = ".";
        File dir = new File( dir_name );  // access the directory 
        long totalSize = get_dirsize( dir ); // get the size of the directory
        System.out.println(totalSize);
    }
    
}

