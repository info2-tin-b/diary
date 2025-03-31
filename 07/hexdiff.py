#!/usr/bin/env python3
import sys
from rich.console import Console
from rich.text import Text

def read_file(path):
    with open(path, 'rb') as f:
        return f.read()

def hexdiff(data1, data2, width=16):
    console = Console()
    len1, len2 = len(data1), len(data2)
    max_len = max(len1, len2)

    for offset in range(0, max_len, width):
        chunk1 = data1[offset:offset+width]
        chunk2 = data2[offset:offset+width]

        line1 = Text()
        line2 = Text()

        for i in range(width):
            b1 = chunk1[i] if i < len(chunk1) else None
            b2 = chunk2[i] if i < len(chunk2) else None

            if b1 is None and b2 is None:
                line1.append("   ")
                line2.append("   ")
            elif b1 is None:
                line1.append("   ", style="italic dim")
                line2.append(f"{b2:02X} ", style="bold green")
            elif b2 is None:
                line1.append(f"{b1:02X} ", style="bold red")
                line2.append("   ", style="italic dim")
            elif b1 == b2:
                line1.append(f"{b1:02X} ", style="dim")
                line2.append(f"{b2:02X} ", style="dim")
            else:
                line1.append(f"{b1:02X} ", style="bold red")
                line2.append(f"{b2:02X} ", style="bold green")

        # Alignement de la ligne supérieure si nécessaire
        line1.append(' ' * (width * 3 - len(line1.plain)))

        console.print(f"{offset:08X}  ", end="")
        console.print(line1, end=" | ")
        console.print(line2)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python hexdiff.py file1.bin file2.bin")
        sys.exit(1)

    hexdiff(read_file(sys.argv[1]), read_file(sys.argv[2]))
