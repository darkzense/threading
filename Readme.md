# Threading

### Usage

1. Specify the variable assets:

```c
...
char word[] = "anna";
long num = 6;
...
```

2. Compile & run
    - Windows (mingw)
    ```bash
    gcc –lpthread -o thread thread.c && ./thread
    ```
    - Linux (gcc)
    ```bash
    gcc -o thread thread.c && ./thread
    ```

### Example Outputs

```
> Waiting for threads to finish (pthread join)
> anna - Is palindrome
> 6 - Is a perfect number
```

```
> Waiting for threads to finish (pthread join)
> hello - Is not palindrome
> 100 - Is not a perfect number
```
