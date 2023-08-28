; --- interrupt.asm -------------------------
; defines the interrupt service routines (ISR)

[extern isr_handler]
[extern irq_handler]


; --- low-level ISR handler -----------------
isr_common_stub:

    ; save CPU state
    pusha           ; save all registers
    mov ax, ds      ; lower 16-bits of eax will be the data segment reg.
    push eax        ; save the data segment
    mov ax, 0x10    ; load kernel data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; call C handler
    call isr_handler

    ; restore state
    pop eax         ; reload original data segment descriptor 
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa            ; reload original registers
    add esp, 8      ; clean pushed error code and ISR index
    sti             ; set interrupt flag
    iret            ; return from interrupt


; --- low-level IRQ handler -----------------
irq_common_stub:

    ; save CPU state
    pusha           ; save all registers
    mov ax, ds      ; lower 16-bits of eax will be the data segment reg.
    push eax        ; save the data segment
    mov ax, 0x10    ; load kernel data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; call C handler
    call irq_handler

    ; restore state
    pop eax         ; reload original data segment descriptor 
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa            ; reload original registers
    add esp, 8      ; clean pushed error code and ISR index
    sti             ; set interrupt flag
    iret            ; return from interrupt
    

; --- ISR & IRQ declaration -----------------
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31
global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15


; --- macros for ISR definitions ------------
%macro NO_ERRCODE 1
    [GLOBAL isr%1]
    isr%1:
        cli                     ; disable interrupts
        push byte %1            ; push a dummy error code
        push byte %1            ; push the interrupt index
        jmp isr_common_stub     ; go to the common handler
%endmacro

%macro ISR_ERRCODE 1
    [GLOBAL isr%1]
    isr%1:
        cli                     ; disable interrupts
        push byte %1            ; push the interrupt index
        jmp isr_common_stub     ; go to the isr common handler
%endmacro


; --- macros for ISR definitions ------------
%macro IRQ 2
    [GLOBAL irq%1]
    irq%1:
        cli                     ; disable interrupts
        push byte 0x00          ; dummy error code
        push byte %2            ; push irq index
        jmp irq_common_stub     ; go to the irq common handler
%endmacro


; --- call macro for each ISR ---------------
NO_ERRCODE  0
NO_ERRCODE  1
NO_ERRCODE  2
NO_ERRCODE  3
NO_ERRCODE  4
NO_ERRCODE  5
NO_ERRCODE  6
NO_ERRCODE  7
ISR_ERRCODE 8
NO_ERRCODE  9
ISR_ERRCODE 10
ISR_ERRCODE 11
ISR_ERRCODE 12
ISR_ERRCODE 13
ISR_ERRCODE 14
NO_ERRCODE  15
NO_ERRCODE  16
NO_ERRCODE  17
NO_ERRCODE  18
NO_ERRCODE  19
NO_ERRCODE  20
NO_ERRCODE  21
NO_ERRCODE  22
NO_ERRCODE  23
NO_ERRCODE  24
NO_ERRCODE  25
NO_ERRCODE  26
NO_ERRCODE  27
NO_ERRCODE  28
NO_ERRCODE  29
NO_ERRCODE  30
NO_ERRCODE  31


; --- call macro for each IRQ ---------------
IRQ     0,      32
IRQ     1,      33
IRQ     2,      34
IRQ     3,      35
IRQ     4,      36
IRQ     5,      37
IRQ     6,      38
IRQ     7,      39
IRQ     8,      40
IRQ     9,      41
IRQ     10,     42
IRQ     11,     43
IRQ     12,     44
IRQ     13,     45
IRQ     14,     46
IRQ     15,     47
