from ui.gui import Ui_MainWindow
from ui.ui import CLI_UI
from PyQt5 import QtWidgets
from domain.board import TestBoard
from domain.plane import TestPlane
from controller.planes_board import TestPlanesBoard
from controller.game import TestGame


TestBoard()
TestPlane()
TestPlanesBoard()
TestGame()
ui = 'gui'

if ui == 'cli':
    pass
    s = CLI_UI().menu()
elif ui == 'gui':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    PlaneWar = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(PlaneWar)
    PlaneWar.show()
    sys.exit(app.exec_())
