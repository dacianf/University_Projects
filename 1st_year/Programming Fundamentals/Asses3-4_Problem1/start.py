import ui_module as cmdUI
import menu_based_UI as menUI

def main():
    menUI.ts.startTesting()
    while True:
        x=input("For command-based usage type 1 and 2 for menu-based usage:")
        if(x=='1'):
            return cmdUI.main()
        elif(x=='2'):
            return menUI.main()
        else:
            print("Incorect command!")
main()