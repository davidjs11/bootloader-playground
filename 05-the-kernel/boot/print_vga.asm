[bits 32]
; this function uses VGA (video graphics array) memory for printing
; characters into the screen in 32-bit protected mode.
; this mode allows memory and I/O protection, and using the GDT table
; but removes BIOS interrupts (they use 16 bits real mode).
; for more info: https://wiki.osdev.org/Protected_mode


; print_vga.asm
; parameters:
;   'ebx' - address of the character buffer
[bits 32]   ; enter 32-bit protected mode

print_vga:
    pusha
    mov edx, 0xB8000    ; get VGA memory address

print_vga_loop:
    ; set character
    mov al, [ebx]   ; get character from buffer
    mov ah, 0x0F    ; (white on black)

    cmp al, 0x0     ; check if null-char has been reached
    je print_vga_end

    mov [edx], ax   ; set character value into VGA memory
    add edx, 2      ; increment VGA buffer pointer
    add ebx, 1      ; increment buffer pointer

    jmp print_vga_loop  ; return to loop 

print_vga_end:
    popa
    ret
