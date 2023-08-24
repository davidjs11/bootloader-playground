[bits 16]       ; now using 16 bits real mode

; switch to protected mode
switch_pm:
    cli                     ; disable all interrupts
    lgdt [gdt_descriptor]   ; set the GDT descriptor

    mov eax, cr0            ; set 32-bit mode bit from control register
    or eax, 0x1             
    mov cr0, eax

    jmp CODE_SEGMENT:init_pm ; initialize protected mode


; init all registers for protected mode
[bits 32]
init_pm:
    ; update segment registers to current data segment
    mov ax, DATA_SEGMENT
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; set the stack at the top of the free space
    mov ebp, 0x90000
    mov esp, ebp

    ; call a label with useful code
    call BEGIN_PM
