from pyfiglet import Figlet
import sys

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) != 3 or sys.argv[1] != "-f" or sys.argv[2] not in fonts:
    sys.exit("Invalid usage")
else:
    message = input('Input: ')
    font = sys.argv[2]

    f = Figlet(font=font)
    print('Output: ')
    print(f.renderText(message))
