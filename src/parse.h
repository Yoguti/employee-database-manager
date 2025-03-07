
#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0x4c4c4144

struct dbheader_t
{
    unsigned int magic;
    unsigned short version;
    unsigned short count;
    unsigned int filesize;
};

struct employee_t
{
    char name[256];
    char address[256];
    unsigned int hours;
};

void list_employees(struct dbheader_t *dbhdr, struct employee_t *employees);
int add_employee (struct dbheader_t *, struct employee_t *, char *);
int create_db_header(int fd, struct dbheader_t **headerOut);
int validate_db_header(int fd, struct dbheader_t **headerOut);
int read_employees(int fd, struct dbheader_t *, struct employee_t **employeesOut);
int output_file(int fd, struct dbheader_t *dbhrd, struct employee_t *employees);

int update_hours(struct dbheader_t *dbhrd, struct employee_t *employees, int hour);
int remove_employee(struct dbheader_t *dbhrd, struct employee_t *employees, char *);

//remove employee
//update their hours

#endif
