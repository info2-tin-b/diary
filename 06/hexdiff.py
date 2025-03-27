#!/usr/bin/env python3
import sys
from rich.console import Console
from rich.text import Text

def read_file(path):
    with open(path, 'rb') as f:
        return f.read()

def hexdiff(data1, data2, width=16):
    console = Console()
    max_len = max(len(data1), len(data2))
    data1 += b'\x00' * (max_len - len(data1))
    data2 += b'\x00' * (max_len - len(data2))

    for offset in range(0, max_len, width):
        chunk1 = data1[offset:offset+width]
        chunk2 = data2[offset:offset+width]

        line1 = Text()
        line2 = Text()

        for b1, b2 in zip(chunk1, chunk2):
            hex1 = f"{b1:02X}"
            hex2 = f"{b2:02X}"
            if b1 == b2:
                line1.append(hex1 + ' ', style="dim")
                line2.append(hex2 + ' ', style="dim")
            else:
                line1.append(hex1 + ' ', style="bold red")
                line2.append(hex2 + ' ', style="bold green")

        console.print(f"{offset:08X}  ", end="")
        console.print(line1, end=" | ")
        console.print(line2)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python hexdiff.py file1.bin file2.bin")
        sys.exit(1)

    f1 = read_file(sys.argv[1])
    f2 = read_file(sys.argv[2])
    hexdiff(f1, f2)
