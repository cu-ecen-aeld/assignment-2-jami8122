#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    
    //setup syslog
    openlog("writer", LOG_PID, LOG_USER);

    if (argc !=3) {
        syslog(LOG_ERR, "Usage is %s <writefile> <writestr>", argv[0]);
        fprintf(stderr, "Usage is %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    syslog(LOG_DEBUG, "writing %s to %s", writestr, writefile);


    // open file to write, create if dne, truncate if exists
    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        // open failure
        syslog(LOG_ERR, "open(%s) failed: %s", writefile, strerror(errno));
        perror("open");
        closelog();
        return 1;
    }

    size_t len = strlen(writestr);
    ssize_t writer = write(fd, writestr, len);
    if (writer < 0) {
        syslog(LOG_ERR, "write(%s) failed: %s",writefile, strerror(errno));
        perror("write");
        close(fd);
        closelog();
        return 1;
    }

    if ((size_t)writer != len) {
        syslog(LOG_ERR, "write(%s) failed: short write", writefile);
        close(fd);
        closelog();
        return 1;
    }

    if (close(fd) == -1) {
        syslog(LOG_ERR, "close(%s) failed: %s", writefile, strerror(errno));
        perror("close");
        closelog();
        return 1;
    }

    closelog();
    return 0;

}