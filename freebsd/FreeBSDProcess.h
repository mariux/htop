/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_FreeBSDProcess
#define HEADER_FreeBSDProcess
/*
htop - FreeBSDProcess.h
(C) 2015 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/


typedef enum FreeBSDProcessFields {
   // Add platform-specific fields here, with ids >= 100
   LAST_PROCESSFIELD = 100,
} FreeBSDProcessField;

typedef struct FreeBSDProcess_ {
   Process super;
} FreeBSDProcess;

#ifndef Process_isKernelThread
#define Process_isKernelThread(_process) (_process->pgrp == 0)
#endif

#ifndef Process_isUserlandThread
#define Process_isUserlandThread(_process) (_process->pid != _process->tgid)
#endif


extern ProcessClass FreeBSDProcess_class;

extern ProcessFieldData Process_fields[];

extern char* Process_pidFormat;
extern char* Process_tpgidFormat;

void Process_setupColumnWidths();

FreeBSDProcess* FreeBSDProcess_new(Settings* settings);

void Process_delete(Object* cast);

void FreeBSDProcess_writeField(Process* this, RichString* str, ProcessField field);

long FreeBSDProcess_compare(const void* v1, const void* v2);

bool Process_isThread(Process* this);

#endif
