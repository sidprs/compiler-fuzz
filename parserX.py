"""
Parser.py
DNA Polyemerase Codon Decipher

"""

class LogReader:
    def __init__(self, file_path:str):
        self.file:str = file_path
        self.number_lines: int = 0 
        self.lines: dict = {}
        self.allowed_chars = set('ATGCatgc')

    def read(self):
        with open(self.file, 'r') as file:
            for line_no , line in enumerate(file, start=1):
                processed_line = line.strip()
                filtered = ''.join(c.upper() for c in processed_line if c in self.allowed_chars)
                if filtered:
                    self.lines[line_no] =  filtered
                    self.number_lines += 1
    
    def print_lines(self):
        for line_num, sequence in self.lines.items():
            print(f"Line {line_num}: {sequence}")




def main()->None:
        
    Log = LogReader("input.txt")
    Log.read()
    Log.print_lines()
    print("hello")

if __name__ == "__main__":
    main()
