import encryptdecrypt as ENC
import tkinter as TK

def encryptButton() :
<<<<<<< HEAD
    encryptvalue.set(ENC.encryptText(encryptvalue.get(),
=======
    evcryptvalue.set(ENC.encryptText(encryptvalue.get(),
>>>>>>> 2ce0eff65e46c9b50e765b6fdcdf223bfb701952
    keyvalue.get()))

def decryptButton() :
    encryptvalue.set(ENC.encryptText(encryptvalue.get(),
    -keyvalue.get()))

# Define Tkinter application
root = TK.Tk()
root.title("Encrypt/Decrypt GUI")
# Set control & test value
encryptvalue = TK.StringVar()
encryptvalue.set("My Message")
keyvalue = TK.IntVar()
keyvalue.set(20)
prompt = "Enter message to encrypt : "
key = "Key : "

label1 = TK.Label(root, text = prompt, width = len(prompt), bg = 'green')
textEnter = TK.Entry(root, textvariable = encryptvalue, width = len(prompt))
encryptButton = TK.Button(root, text = "Encrypt", command = encryptButton)
decryptButton = TK.Button(root, text = "Decrypt", command = decryptButton)
label2 = TK.Label(root, text = key, width = len(key))
keyEnter = TK.Entry(root, textvariable = keyvalue, width = 8)

# Set layout
label1.grid(row = 0, columnspan = 2, sticky = TK.E + TK.W)
textEnter.grid(row = 1, columnspan = 2, sticky = TK.E + TK.W)
<<<<<<< HEAD
encryptButton.grid(row = 2, column = 0, sticky = TK.E)
decryptButton.grid(row = 2, column = 1, sticky = TK.W)
label2.grid(row = 3, column = 0, sticky = TK.E)
keyEnter.grid(row = 3, column = 1, sticky = TK.W)
=======
encryptButton.gird(row = 2, column = 0, sticky = TK.E)
decryptButton.grid(row = 2, column = 1, sticky = TK.W)
label2.grid(row = 3, column = 0, sticky = TK.E)
keyEnter.grid(row = 3, column = 1, stickey = TK.W)
>>>>>>> 2ce0eff65e46c9b50e765b6fdcdf223bfb701952

TK.mainloop()
#End