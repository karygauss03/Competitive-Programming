import re

file_path = "Contests/Advent of Code/2024/in.txt"

def main():
    with open(file_path, "r") as file:
        ans = 0
        mul_pattern = re.compile(r"mul\((\d+),(\d+)\)")
        
        for line in file:
            while True:
                match = mul_pattern.search(line)
                if not match:
                    break
                x, y = int(match.group(1)), int(match.group(2))
                ans += x * y
                line = line[match.end():]
        
        print(ans)

if __name__ == "__main__":
    main()
