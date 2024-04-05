#ifndef SSH_H
#define SSH_H

#endif // SSH_H


#include <string>

#include <iostream>

#include "config.h"

// not using scp or sftp with libssh2 because it's too difficult to transfer folders.


// using sshpass and scp commands with system()
// for example
// sshpass -p "114514" scp -o StrictHostKeyChecking=no -r user@127.0.0.1:/home/user/6/ .

// although sshpass is not pre-installed on most gnu/linux distributions and windows

/*
// ssh-related config strings
std::string host = "127.0.0.1";
std::string username = "user";
std::string password = "1";
std::string ssh_options = "-o StrictHostKeyChecking=no ";
*/

void scp_get_files_from_remote(std::string remote_dir, std::string local_dir)
{
    std::string scp_command = "sshpass -p '"
                              + password
                              + "' scp -r "
                              + ssh_options
                              + username
                              + "@"
                              + host
                              + ":"
                              + remote_dir
                              + " "
                              + local_dir;
    std::cout<<scp_command<<"\n";
    system(scp_command.c_str());
}

void scp_push_local_files_to_remote(std::string remote_dir, std::string local_dir)
{
    std::string scp_command = "sshpass -p '"
                              + password
                              + "' scp -r "
                              + ssh_options
                              + local_dir
                              + " "
                              + username
                              + "@"
                              + host
                              + ":"
                              + remote_dir ;
    std::cout<<scp_command<<"\n";
    system(scp_command.c_str());
}

