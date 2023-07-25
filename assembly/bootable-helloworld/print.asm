; prints a character pointed by the address in 'bx'
print:
    pusha ; save all registers in the stack

print_start:
    ; check if current character is 0x00
    mov al, [bx]    ; load into 'al' register
    cmp al, 0
    je print_finish ; finish if =

    ; print
    mov ah, 0x0E    ; set TTY mode
    int 0x10

    ; increment pointer and go back
    add bx, 1
    jmp print_start 

print_finish:
    popa ; restore all registers from stack
    ret

; prints a new line (wow)
newline:
    pusha
    mov ax, 0x0E0A  ; new line
    int 0x10
    mov al, 0x0D    ; carriage return
    int 0x10
    popa
    ret
