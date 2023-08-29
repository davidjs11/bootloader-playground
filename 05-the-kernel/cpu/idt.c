/// idt.c ///////////////////////////////////

#include "ports.h"
#include "idt.h"
#include "isr.h"


/// IDT /////////////////////////////////////

idt_entry_t idt_entries[IDT_ENTRIES];
idt_ptr_t   idt_ptr;


/// IDT utilities ///////////////////////////

// initialize the IDT
void idt_init()
{
    // initialize the PIC
    port_byteOut(0x20, 0x11);   // initialize master PIC
    port_byteOut(0xA0, 0x11);   // initialize slave PIC

    // map IRQ table
    port_byteOut(0x21, 0x20);   // master PIC vector offset
    port_byteOut(0xA1, 0x28);   // slave PIC vector offset
    port_byteOut(0x21, 0x04);   // master! there's a slave at IRQ2
    port_byteOut(0xA1, 0x02);   // slave! you have cascade identity 

    // tell them to use 8086 mode
    port_byteOut(0x21, 0x01);
    port_byteOut(0xA1, 0x01);

    port_byteOut(0x21, 0x00);
    port_byteOut(0xA1, 0x00);


    // set entries in the IDT (ISR and IRQ)
    idt_set_entry(0,  (u32) isr0,  0x08, 0x8E);
    idt_set_entry(1,  (u32) isr1,  0x08, 0x8E);
    idt_set_entry(2,  (u32) isr2,  0x08, 0x8E);
    idt_set_entry(3,  (u32) isr3,  0x08, 0x8E);
    idt_set_entry(4,  (u32) isr4,  0x08, 0x8E);
    idt_set_entry(5,  (u32) isr5,  0x08, 0x8E);
    idt_set_entry(6,  (u32) isr6,  0x08, 0x8E);
    idt_set_entry(7,  (u32) isr7,  0x08, 0x8E);
    idt_set_entry(8,  (u32) isr8,  0x08, 0x8E);
    idt_set_entry(9,  (u32) isr9,  0x08, 0x8E);
    idt_set_entry(10, (u32) isr10, 0x08, 0x8E);
    idt_set_entry(11, (u32) isr11, 0x08, 0x8E);
    idt_set_entry(12, (u32) isr12, 0x08, 0x8E);
    idt_set_entry(13, (u32) isr13, 0x08, 0x8E);
    idt_set_entry(14, (u32) isr14, 0x08, 0x8E);
    idt_set_entry(15, (u32) isr15, 0x08, 0x8E);
    idt_set_entry(16, (u32) isr16, 0x08, 0x8E);
    idt_set_entry(17, (u32) isr17, 0x08, 0x8E);
    idt_set_entry(18, (u32) isr18, 0x08, 0x8E);
    idt_set_entry(19, (u32) isr19, 0x08, 0x8E);
    idt_set_entry(20, (u32) isr20, 0x08, 0x8E);
    idt_set_entry(21, (u32) isr21, 0x08, 0x8E);
    idt_set_entry(22, (u32) isr22, 0x08, 0x8E);
    idt_set_entry(23, (u32) isr23, 0x08, 0x8E);
    idt_set_entry(24, (u32) isr24, 0x08, 0x8E);
    idt_set_entry(25, (u32) isr25, 0x08, 0x8E);
    idt_set_entry(26, (u32) isr26, 0x08, 0x8E);
    idt_set_entry(27, (u32) isr27, 0x08, 0x8E);
    idt_set_entry(28, (u32) isr28, 0x08, 0x8E);
    idt_set_entry(29, (u32) isr29, 0x08, 0x8E);
    idt_set_entry(30, (u32) isr30, 0x08, 0x8E);
    idt_set_entry(31, (u32) isr31, 0x08, 0x8E);
    idt_set_entry(32, (u32) irq0,  0x08, 0x8E);
    idt_set_entry(33, (u32) irq1,  0x08, 0x8E);
    idt_set_entry(34, (u32) irq2,  0x08, 0x8E);
    idt_set_entry(35, (u32) irq3,  0x08, 0x8E);
    idt_set_entry(36, (u32) irq4,  0x08, 0x8E);
    idt_set_entry(37, (u32) irq5,  0x08, 0x8E);
    idt_set_entry(38, (u32) irq6,  0x08, 0x8E);
    idt_set_entry(39, (u32) irq7,  0x08, 0x8E);
    idt_set_entry(40, (u32) irq8,  0x08, 0x8E);
    idt_set_entry(41, (u32) irq9,  0x08, 0x8E);
    idt_set_entry(42, (u32) irq10, 0x08, 0x8E);
    idt_set_entry(43, (u32) irq11, 0x08, 0x8E);
    idt_set_entry(44, (u32) irq12, 0x08, 0x8E);
    idt_set_entry(45, (u32) irq13, 0x08, 0x8E);
    idt_set_entry(46, (u32) irq14, 0x08, 0x8E);
    idt_set_entry(47, (u32) irq15, 0x08, 0x8E);

    // set the pointer to the IDT array
    idt_ptr.base  = (u32) &idt_entries;
    idt_ptr.limit = IDT_ENTRIES * sizeof(idt_entry_t) - 1;

    // load/refresh the IDT
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_ptr));
    __asm__ __volatile__ ("sti");
}

// set an entry in the IDT
void idt_set_entry(u8 index, u32 base, u16 sel, u8 flags)
{
    // set the base pointer
    idt_entries[index].base_low = LOWEST16(base);
    idt_entries[index].base_high = HIGHEST16(base);

    // other data
    idt_entries[index].sel = sel;
    idt_entries[index].flags = flags /* | 0x60 */;
    idt_entries[index].always0 = 0x00;
}
