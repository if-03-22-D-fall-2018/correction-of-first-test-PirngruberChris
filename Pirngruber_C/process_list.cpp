/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>
#include "process_list.h"

 void init_process_list (ProcessList *pl)
 {
   pl->length = 0;
 }

 int get_length (const ProcessList *pl)
 {
   return pl->length;
 }

 bool add_entry (ProcessList *pl, struct ProcessListEntry *e)
 {
   if (pl->length <= MAX_LIST_ENTRIES) {    //if impleemented
     pl->processes[pl->length] = e;
     pl->length++;
     return true;
   }
   return false;    //return value changed
 }


 bool add_entries (ProcessList *pl, struct ProcessListEntry *e[], int n)
 {
   if (pl->length+ n <= MAX_LIST_ENTRIES) {     //function new implemented
     for (int i = 0; i < n; i++) {
       add_entry(pl, e[i]);
     }
     return true;
   }
   return false;
 }

 int get_process_with_id (const ProcessList *pl, int id, struct ProcessListEntry *result_list[])
 {
   for (int i = 0; i < get_length(pl); i++) {   //function new implemented
     if (pl->processes[i]->pid == id) {
       result_list[0] = pl->processes[i];
       return 1;
     }
   }
   return 0;
 }

 int get_processes_with_state (const ProcessList *pl, enum ProcessState state, struct ProcessListEntry *result_list[])
 {
   int found = 0;
   for (int i = 0; i < get_length(pl); i++) {   //function new implemented
     if (pl->processes[i]->state == state) {
       result_list[found] = pl->processes[i];
      found++;
     }
   }
   return found;
 }

 struct ProcessListEntry * 	get_process_with_highest_cpu_consumption (const  ProcessList *pl)
 {
   struct ProcessListEntry* ple = pl->processes[0];   //function new implemented
   if (get_length(pl) == 0)
   {
     return 0;
   }
   if (get_length(pl) == 1)
   {
    return pl->processes[0];
   }
   for (int j = 0; j < get_length(pl); j++) {
     if (ple->cpu_usage < pl->processes[j]->cpu_usage)
     {
       ple = pl->processes[j];
     }
   }
   return ple;
 }

 struct ProcessListEntry * 	get_process_with_lowest_cpu_consumption (const  ProcessList *pl)
 {
   struct ProcessListEntry* ple = pl->processes[0];   // function new implemented
  if (get_length(pl) == 0)
  {
    return 0;
  }
  if (get_length(pl) == 1)
  {
    return pl->processes[0];
  }
  for (int j = 0; j < get_length(pl); j++) {
    if (ple->cpu_usage > pl->processes[j]->cpu_usage)
    {
      ple = pl->processes[j];
    }
  }
  return ple;
 }

  int get_top_n_processes_cpu(const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
  {
    return 0;
  }

  int get_bottom_n_processes_cpu(const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
  {
    return 0;
  }
