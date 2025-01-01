import re

file_path = "Contests/Advent of Code/2024/in.txt"

def main():
    with open(file_path, "r") as file:
        ans = 0
        mul_pattern = re.compile(r"mul\((\d+),(\d+)\)")
        do_pattern = re.compile(r"do\(\)")
        dont_pattern = re.compile(r"don't\(\)")
        
        is_enabled = True
        
        for line in file:
            while True:
                do_match = do_pattern.search(line)
                dont_match = dont_pattern.search(line)
                mul_match = mul_pattern.search(line)
                
                if not (do_match or dont_match or mul_match):
                    break
                
                next_match = min(
                    filter(None, [do_match, dont_match, mul_match]),
                    key=lambda m: m.start()
                )
                
                if next_match == do_match:
                    is_enabled = True
                    line = line[next_match.end():]
                elif next_match == dont_match:
                    is_enabled = False
                    line = line[next_match.end():]
                elif next_match == mul_match:
                    if is_enabled:
                        x, y = int(next_match.group(1)), int(next_match.group(2))
                        ans += x * y
                    line = line[next_match.end():]
        
        print(ans)

if __name__ == "__main__":
    main()

