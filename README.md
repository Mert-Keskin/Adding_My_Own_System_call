# Adding_My_Own_System_call
**I added my own system call function into linux kernel and comipled it.**

**Here is a brief explanation how you can also add your own system call function.**

1. Download the linux kernel via command "sudo apt-get source linux-source".

2. Extract the folder "tar xvf linux-downloaded_version".

3. To edit the config file of the kernel, you will create from the existing config file in the system. "yes "" | make oldconfig".

4. Change the version name in .config (it will be added with this name when the kernel is added to the system)

5. CONFIG_LOCALVERSION="-your_string"

6. Run this commands to not the get certificate errors "scripts/config --disable SYSTEM_TRUSTED_KEYS", "scripts/config --disable SYSTEM_REVOCATION_KEYS"

7. In the Linux kernel you downloaded, go to the arch/x86/entry/syscalls/syscall_64.tbl file and add your own system call with the next number at the end of the system calls. It should be close to 330. For example, if the next number is 335 
335	  common    desired_name    sys_desired_name
There is tab in between!

8. In the Linux kernel you downloaded, add the code you wanted to the kernel/sys.c. You can see mine is at the end of the file.

9. Compile the kernel "make -j4"

10. Compile and install modules "make -j4 modules_install"

11. Installing the kernel in /boot and grub menus "make install"

12. Test your system call. I write a test.c for that.
