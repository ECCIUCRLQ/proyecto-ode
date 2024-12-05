#                         %rdi            %rsi           %rdx      %rcx
# void subValues(uint8_t* values, uint8_t increment, int size, int color); 
.section .text              # inicia la sección de código ejecutable
.global subValues
subValues:
mov $0, %rbx                # Contador en 0

cmp $1, %rcx                # Modificar solo valor R
je red
cmp $2, %rcx                # Modificar solo valor G
je green
cmp $3, %rcx                # Modificar solo valor B
je blue

mov $0, %r8
loopRGB:
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor B
call doSum
inc %r8
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor G
call doSum
inc %r8
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor R
call doSum
inc %r8
inc %rbx                    # Incrementa el contador
cmp %rdx, %rbx              # Calcula si ya alcanzo el ultimo valor
jne loopRGB
ret
blue:
mov $0, %r8
loopB:
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor
call doSum
add $3, %r8
inc %rbx                    # Incrementa el contador
cmp %rdx, %rbx              # Calcula si ya alcanzo el ultimo valor
jne loopB
ret

green:
mov $1, %r8                # Genera offset para solo aumentar los valores G
loopG:
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor
call doSum
add $3, %r8
inc %rbx                    # Incrementa el contador
cmp %rdx, %rbx              # Calcula si ya alcanzo el ultimo valor
jle loopG
ret

red:
mov $2, %r8                # Genera offset para solo aumentar los valores R
loopR:
movzx (%rdi, %r8, 1), %rax # Operar siguiente valor
call doSum
inc %r8
inc %r8
inc %r8
inc %rbx                    # Incrementa el contador
cmp %rdx, %rbx              # Calcula si ya alcanzo el ultimo valor
jne loopR
ret

doSum:
sub %rsi, %rax
cmp $0, %rax                # Evita que se un numero mayor a 255
jge next
movb $0, %al
next:
movb %al, (%rdi, %r8, 1)    # Coloca el nuevo valor en el arreglo
ret
