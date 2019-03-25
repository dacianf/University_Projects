'''
Created on 1 Feb 2019

@author: Daci
'''

from controller.game import Game
from domain.square import Square


def start():
    game = Game()
    
    print(game.displayBoard())

    def place(cmd):
        pat = game.loadPattern(cmd[0])
        game.placePattern(pat, Square(int(cmd[1][0]), int(cmd[1][2])))
        
    def tick(cmd):
        if len(cmd) == 0:
            game.update()
        else:
            game.update(int(cmd[0]))
    
    def save(cmd):
        game.saveState(cmd[0])
    
    def load(cmd):
        game.loadState(cmd[0])
    
    def exitt(cmd):
        exit()

    commands = {'place': place, 'tick': tick, 'save': save, 'load': load, 'exit': exitt}
    try:
        while True:
            cmd = input('> ')
            strg = cmd.split(' ')
            if len(strg) > 1:
                commands[strg[0]](strg[1:])
            else:
                commands[strg[0]]([])
            print(game.displayBoard())
    except Exception as err:
            print('Error: ' + str(err))

        
start()
