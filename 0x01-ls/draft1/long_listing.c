#include "headerfile.h"
/**
 * long_listing - function to list the details of the given file or dir
 * @av: argument string
 * @path: parent path if specified (not null)
 */
void long_listing(char *av, char *path)
{
        int permnum, npflag = 0;
        char *timeval, *newpath;
        struct stat my_stats;
        struct passwd *usr;
        struct group *grp;

        if (path == NULL)
                newpath = av;
        else
                newpath = mall_strcat(path, av, "/"), npflag = 1;
        permnum = my_stats.st_mode;
        if (lstat(newpath, &my_stats) != -1)
        {
                if (S_ISDIR(permnum))
                        printf("d");
                else if (S_ISLNK(permnum))
                        printf("l");
                else
                        printf("-");
                show_permission(permnum);
                printf(" %d", (int)my_stats.st_nlink);
                usr = getpwuid(my_stats.st_uid);
                grp = getgrgid(my_stats.st_gid);
                if (usr != NULL)
                        printf(" %s ", usr->pw_name);
                else
                        printf(" %d ", (int)my_stats.st_uid);
                if (grp != NULL)
                        printf("%s ", grp->gr_name);
                else
                        printf("%d ", (int)my_stats.st_gid);
                printf("%d ", (int)my_stats.st_size);
                timeval = ctime(&(my_stats.st_mtime));
                printf("%.12s ", &(timeval[4]));
        }
        if (npflag == 1)
                free(newpath);
}

/**
 * show_permission - function to print the file permission.
 * @permnum: permission number
 */
void show_permission(int permnum)
{
        char *permphrase = "rwxrwxrwx";
        int numlimit = 0, num = permnum;

        while (numlimit < 9)
        {
                num = num << 1;
                if (num & 512)
                {
                        printf("%c", permphrase[numlimit]);
                }
                else
                        printf("-");
                numlimit++;
        }
}
