// #define __NR_read 0
int sys_read(long fd, char *buf, unsigned long len)
{
     long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov $0, %%rax\n"
        "syscall" : : "g"(fd), "g"(buf), "g"(len));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_write 1
long sys_write(long fd, char *buf, unsigned long len)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov $1, %%rax\n"
        "syscall" : : "g"(fd), "g"(buf), "g"(len));
    asm("mov %%rax, %0" : "=r"(ret));
    return ret;
}

// #define __NR_open 2
long sys_open(const char *path, unsigned long flags, long mode)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov $2, %%rax\n"
        "syscall" : : "g"(path), "g"(flags), "g"(mode));
    asm ("mov %%rax, %0" : "=r"(ret));
    
    return ret;
}

// #define __NR_close 3
int sys_close(unsigned int fd)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov $3, %%rax\n"
        "syscall" : : "g"(fd));
    return (int)ret;
}

// #define __NR_stat 4
// #define __NR_fstat 5
int sys_fstat(long fd, void *buf)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov $5, %%rax\n"
        "syscall" : : "g"(fd), "g"(buf));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_lssek 8
long sys_lseek(long fd, long offset, unsigned int whence)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov $8, %%rax\n"
        "syscall" : : "g"(fd), "g"(offset), "g"(whence));
    asm("mov %%rax, %0" : "=r"(ret));
    return ret;
}

// #define __NR_mmap 9
void *sys_mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, long fd, unsigned long off)
{
    long mmap_fd = fd;
    unsigned long mmap_off = off;
    unsigned long mmap_flags = flags;
    unsigned long ret;

    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov %3, %%r10\n"
        "mov %4, %%r8\n"
        "mov %5, %%r9\n"
        "mov $9, %%rax\n"
        "syscall\n" : : "g"(addr), "g"(len), "g"(prot), "g"(flags), "g"(mmap_fd), "g"(mmap_off));
    asm ("mov %%rax, %0" : "=r"(ret));              
    return (void *)ret;
}

// #define __NR_mprotect 10
int sys_mprotect(void * addr, unsigned long len, int prot)
{
    unsigned long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov $10, %%rax\n"
        "syscall" : : "g"(addr), "g"(len), "g"(prot));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_munmap 11
int sys_munmap(void *addr, size_t len)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"/
        "mov $11, %%rax\n"
        "syscall" :: "g"(addr), "g"(len));
    asm ("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_exit 60
void sys_exit(long status)
{
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov $60, %%rax\n"
        "syscall" : : "r"(status));
}

// #define __NR_fsync 74
int sys_fsync(int fd)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov $74, %%rax\n"
        "syscall" : : "g"(fd));
    asm ("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_rename 82
int sys_rename(const char *old, const char *new)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov $82, %%rax\n"
        "syscall" ::"g"(old),"g"(new));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}

// #define __NR_unlink 87
int sys_unlink(const char *path)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov $87, %%rax\n"
        "syscall" ::"g"(path));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
    }

// #define __NR_ptrace 101
long sys_ptrace(long request, long pid, void *addr, void *data)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov %3, %%r10\n"
        "mov $101, %%rax\n"
        "syscall" : : "g"(request), "g"(pid), "g"(addr), "g"(data));
    asm("mov %%rax, %0" : "=r"(ret));
    return ret;
}

// #define __NR_prctl 157
int sys_prctl(long option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5)
{
    long ret;
    __asm__ volatile(
        "mov %0, %%rdi\n"
        "mov %1, %%rsi\n"
        "mov %2, %%rdx\n"
        "mov %3, %%r10\n"
        "mov $157, %%rax\n"
        "syscall\n" :: "g"(option), "g"(arg2), "g"(arg3), "g"(arg4), "g"(arg5));
    asm("mov %%rax, %0" : "=r"(ret));
    return (int)ret;
}
