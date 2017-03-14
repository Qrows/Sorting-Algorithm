/*
 *
 */

struct Record {
        
        int data;
        struct Record *next;
};
typedef struct Record Record;

struct DoubleRecord {
        
        int data;
        struct DoubleRecord *prev;
        struct DoubleRecord *next;
};
typedef struct DoubleRecord DoubleRecord;
