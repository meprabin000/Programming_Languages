/* 
Prabin Lamichhane
1001733599
OS - Windows (tested on omega)
*/

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

long int get_dirsize( char* path );


int main( void )
{
    printf("%lu is the size\n", get_dirsize("."));
    return 0;
}

long int get_dirsize( char* path )
{
    DIR *direc = opendir( path ); // accesses the directory 
    struct dirent* direntp;
    struct stat statp;
    long int size = 0;
    char new_filepath[1024];

    if( !direc )
    {
        printf("Could not open the current directory %s.\n", path);
        return 0;
    }
    while( (direntp = readdir(direc)) ) // read the directory and store store the directory meta data on direntp
    {
        // filter the unnecessary directory
        if( strcmp( direntp->d_name, ".") == 0 || strcmp( direntp->d_name, ".." ) == 0)
            continue;

        sprintf(new_filepath, "%s/%s", path, direntp->d_name);
        if( lstat(new_filepath, &statp) ) // store the directory stats such as size in statp structure
        {
            perror("Error on lstat: ");
            continue;
        }
        if( S_ISDIR( statp.st_mode ) ) // check whether directory pointed by statp is a folder
        {
            size += get_dirsize( new_filepath ); // if folder recursively call the function and go inside the directory
        }
        else // if it is file
        {
            size += statp.st_size; // get the size of the file and add it to size
        }
    }
    closedir( direc ); // close the directory
    return size; // return the final size
}