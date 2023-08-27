/// irt.h ///////////////////////////////////
#ifndef IDT_H
#define IDT_H

#include "types.h"

#define IDT_ENTRIES 256     // number of entries of the IDT
#define KERNEL_CS   0x08    // segment selector


/// IDT structures //////////////////////////
// struct that defines an entry in the IDT
typedef struct {
    u16 base_low;   // lower 16 bits of address to jump to
    u16 sel;        // kernel segment selector
    u8  always0;    // this one is always 0
    u8  flags;      // flags (check documentation)
    u16 base_high;  // higher 16 bits of address to jump to
} __attribute__((packed)) idt_entry_t; 


// struct that defines a pointer to an array of
// interrupt handlers
typedef struct {
    u16 limit;      // size of the array
    u32 base;       // address of the first entry
} __attribute__((packed)) idt_ptr_t;

extern idt_entry_t idt_entries[IDT_ENTRIES];
extern idt_ptr_t   idt_ptr;

/// functions ///////////////////////////////
void idt_init();
void idt_set_entry(u8 index, u32 base, u16 sel, u8 flags);


#endif  // IDT_H
