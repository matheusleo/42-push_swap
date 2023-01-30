# 42-libft

O objetivo do projeto é criar uma biblioteca em C chamada **libft**: uma coleção de funções que poderão ser reutilizadas no futuro em outros projetos. Além disso, também é aprender os fundamentos e conceitos imporatantes de programação em C.

## Compilação

### Mandatório

Para compilar a parte mandatória do projeto, basta executar o seguinte comando na root do projeto:

```
make
```
A parte mandatória consitia em implementar uma série de funções dividas em dois grupos diferentes:

1. Funções de libc - uma série de funções que já existiam em outras bibliotecas de C

| Biblioteca | Funcões |
|---|---|
| <ctype.h> | [isdigit](ft_isdigit.c) [isalnum](ft_isalnum.c) [isalpha](ft_isalpha.c) [isascii](ft_isascii.c) [isprint](ft_isprint.c) [toupper](ft_toupper.c) [tolower](ft_tolower.c)|
| <string.h> - strings | [strlen](ft_strlen.c) [strchr](ft_strchr.c) [strrchr](ft_strrchr.c) [strncmp](ft_strncmp.c) [strdup](ft_strdup.c)
| <string.h> - memory | [memset](ft_memset.c) [memcpy](ft_memcpy.c) [memmove](ft_memmove.c) [memchr](ft_memchr.c) [memcmp](ft_memcmp.c)|
| <bsd/string.h> | [strnstr](ft_strnstr.c) [strlcpy](ft_strlcpy.c) [strlcat](ft_strlcat.c) |
| <stdlib.h> | [atoi](ft_atoi.c) [calloc](ft_calloc.c) |
| <strings.h> | [bzero](ft_bzero.c) |

2. Funções adicionais - outra série de funções que deveriam ser criadas do 0 com base nas especificações passadas para cada uma

| Relacionados à | Funções |
| --- | --- |
| strings |[ft_strjoin](ft_strjoin.c)  [ft_strmapi](ft_strmapi.c)  [ft_split](ft_split.c)  [ft_itoa](ft_itoa.c)  [ft_striteri](ft_striteri.c)  [ft_strtrim](ft_strtrim.c)  [ft_substr](ft_substr.c) |
| file descriptors | [ft_putchar_fd](ft_putchar_fd.c) [ft_putstr_fd](ft_putstr_fd.c) [ft_putendl_fd](ft_putendl_fd.c) [ft_putnbr_fd](ft_putnbr_fd.c) |


### Bônus

Para compilar a parte bônus do projeto, basta executar o seguinte comando também na root do projeto.

```
make bonus
```
A parte bônus do projeto consistia em criar uma série de funções relacionadas ao conceito de `lista ligada`, do inglês `linked list`.

`Listas ligadas` são um tipo comum de estrutura de dados que permite, por exemplo, a criação de um array sem limite de tamanho pré-definido e associar elementos nessa lista que não são contínuos na memória do computador.

| Funções |
| --- |
| [ft_lstnew](ft_lstnew_bonus.c) |
| [ft_lstadd_front](ft_lstadd_front_bonus.c) |
| [ft_lstsize](ft_lstsize_bonus.c) |
| [ft_lstlast](ft_lstlast_bonus.c) |
| [ft_lstadd_back](ft_lstadd_back_bonus.c) |
| [ft_lstdelone](ft_lstdelone_bonus.c) |
| [ft_lstclear](ft_lstclear_bonus.c) |
| [ft_lstiter](ft_lstiter_bonus.c) |
| [ft_lstmap](ft_lstmap_bonus.c) |

## Execução

Para utilizar as funções da biblioteca ``libft``, basta executar um dos comandos anteriores e compilar uma função principal que utiliza umas das funções que compõe a lib:

```
<COMPILADOR> -Wall -Wextra -Werror <FILE> libft.a
```
