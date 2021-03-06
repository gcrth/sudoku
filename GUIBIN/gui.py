from tkinter import *
from tkinter import messagebox
import tkinter.font as tkFont
import numpy as np

changelist =np.array(
	[
		[0,3,6,1,4,7,2,5,8],
		[0,3,6,1,4,7,2,8,5],
		[0,3,6,1,4,7,5,2,8],
		[0,3,6,1,4,7,5,8,2],
		[0,3,6,1,4,7,8,2,5],
		[0,3,6,1,4,7,8,5,2],

		[0,3,6,1,7,4,2,5,8],
		[0,3,6,1,7,4,2,8,5],
		[0,3,6,1,7,4,5,2,8],
		[0,3,6,1,7,4,5,8,2],
		[0,3,6,1,7,4,8,2,5],
		[0,3,6,1,7,4,8,5,2],

		[0,3,6,4,1,7,2,5,8],
		[0,3,6,4,1,7,2,8,5],
		[0,3,6,4,1,7,5,2,8],
		[0,3,6,4,1,7,5,8,2],
		[0,3,6,4,1,7,8,2,5],
		[0,3,6,4,1,7,8,5,2],

		[0,3,6,4,7,1,2,5,8],
		[0,3,6,4,7,1,2,8,5],
		[0,3,6,4,7,1,5,2,8],
		[0,3,6,4,7,1,5,8,2],
		[0,3,6,4,7,1,8,2,5],
		[0,3,6,4,7,1,8,5,2],

		[0,3,6,7,1,4,2,5,8],
		[0,3,6,7,1,4,2,8,5],
		[0,3,6,7,1,4,5,2,8],
		[0,3,6,7,1,4,5,8,2],
		[0,3,6,7,1,4,8,2,5],
		[0,3,6,7,1,4,8,5,2],

		[0,3,6,7,4,1,2,5,8],
		[0,3,6,7,4,1,2,8,5],
		[0,3,6,7,4,1,5,2,8],
		[0,3,6,7,4,1,5,8,2],
		[0,3,6,7,4,1,8,2,5],
		[0,3,6,7,4,1,8,5,2],

		[0,6,3,1,4,7,2,5,8],
		[0,6,3,1,4,7,2,8,5],
		[0,6,3,1,4,7,5,2,8],
		[0,6,3,1,4,7,5,8,2],
		[0,6,3,1,4,7,8,2,5],
		[0,6,3,1,4,7,8,5,2],

		[0,6,3,1,7,4,2,5,8],
		[0,6,3,1,7,4,2,8,5],
		[0,6,3,1,7,4,5,2,8],
		[0,6,3,1,7,4,5,8,2],
		[0,6,3,1,7,4,8,2,5],
		[0,6,3,1,7,4,8,5,2],

		[0,6,3,4,1,7,2,5,8],
		[0,6,3,4,1,7,2,8,5],
		[0,6,3,4,1,7,5,2,8],
		[0,6,3,4,1,7,5,8,2],
		[0,6,3,4,1,7,8,2,5],
		[0,6,3,4,1,7,8,5,2],

		[0,6,3,4,7,1,2,5,8],
		[0,6,3,4,7,1,2,8,5],
		[0,6,3,4,7,1,5,2,8],
		[0,6,3,4,7,1,5,8,2],
		[0,6,3,4,7,1,8,2,5],
		[0,6,3,4,7,1,8,5,2],

		[0,6,3,7,1,4,2,5,8],
		[0,6,3,7,1,4,2,8,5],
		[0,6,3,7,1,4,5,2,8],
		[0,6,3,7,1,4,5,8,2],
		[0,6,3,7,1,4,8,2,5],
		[0,6,3,7,1,4,8,5,2],

		[0,6,3,7,4,1,2,5,8],
		[0,6,3,7,4,1,2,8,5],
		[0,6,3,7,4,1,5,2,8],
		[0,6,3,7,4,1,5,8,2],
		[0,6,3,7,4,1,8,2,5],
		[0,6,3,7,4,1,8,5,2],


		[0,3,6,2,5,8,1,4,7],
		[0,3,6,2,8,5,1,4,7],
		[0,3,6,5,2,8,1,4,7],
		[0,3,6,5,8,2,1,4,7],
		[0,3,6,8,2,5,1,4,7],
		[0,3,6,8,5,2,1,4,7],

		[0,3,6,2,5,8,1,7,4],
		[0,3,6,2,8,5,1,7,4],
		[0,3,6,5,2,8,1,7,4],
		[0,3,6,5,8,2,1,7,4],
		[0,3,6,8,2,5,1,7,4],
		[0,3,6,8,5,2,1,7,4],

		[0,3,6,2,5,8,4,1,7],
		[0,3,6,2,8,5,4,1,7],
		[0,3,6,5,2,8,4,1,7],
		[0,3,6,5,8,2,4,1,7],
		[0,3,6,8,2,5,4,1,7],
		[0,3,6,8,5,2,4,1,7],

		[0,3,6,2,5,8,4,7,1],
		[0,3,6,2,8,5,4,7,1],
		[0,3,6,5,2,8,4,7,1],
		[0,3,6,5,8,2,4,7,1],
		[0,3,6,8,2,5,4,7,1],
		[0,3,6,8,5,2,4,7,1],

		[0,3,6,2,5,8,7,1,4],
		[0,3,6,2,8,5,7,1,4],
		[0,3,6,5,2,8,7,1,4],
		[0,3,6,5,8,2,7,1,4],
		[0,3,6,8,2,5,7,1,4],
		[0,3,6,8,5,2,7,1,4],

		[0,3,6,2,5,8,7,4,1],
		[0,3,6,2,8,5,7,4,1],
		[0,3,6,5,2,8,7,4,1],
		[0,3,6,5,8,2,7,4,1],
		[0,3,6,8,2,5,7,4,1],
		[0,3,6,8,5,2,7,4,1],

		[0,6,3,2,5,8,1,4,7],
		[0,6,3,2,8,5,1,4,7],
		[0,6,3,5,2,8,1,4,7],
		[0,6,3,5,8,2,1,4,7],
		[0,6,3,8,2,5,1,4,7],
		[0,6,3,8,5,2,1,4,7],

		[0,6,3,2,5,8,1,7,4],
		[0,6,3,2,8,5,1,7,4],
		[0,6,3,5,2,8,1,7,4],
		[0,6,3,5,8,2,1,7,4],
		[0,6,3,8,2,5,1,7,4],
		[0,6,3,8,5,2,1,7,4],

		[0,6,3,2,5,8,4,1,7],
		[0,6,3,2,8,5,4,1,7],
		[0,6,3,5,2,8,4,1,7],
		[0,6,3,5,8,2,4,1,7],
		[0,6,3,8,2,5,4,1,7],
		[0,6,3,8,5,2,4,1,7],

		[0,6,3,2,5,8,4,7,1],
		[0,6,3,2,8,5,4,7,1],
		[0,6,3,5,2,8,4,7,1],
		[0,6,3,5,8,2,4,7,1],
		[0,6,3,8,2,5,4,7,1],
		[0,6,3,8,5,2,4,7,1],

		[0,6,3,2,5,8,7,1,4],
		[0,6,3,2,8,5,7,1,4],
		[0,6,3,5,2,8,7,1,4],
		[0,6,3,5,8,2,7,1,4],
		[0,6,3,8,2,5,7,1,4],
		[0,6,3,8,5,2,7,1,4],

		[0,6,3,2,5,8,7,4,1],
		[0,6,3,2,8,5,7,4,1],
		[0,6,3,5,2,8,7,4,1],
		[0,6,3,5,8,2,7,4,1],
		[0,6,3,8,2,5,7,4,1],
		[0,6,3,8,5,2,7,4,1],
	])

tableBuf=np.zeros((9,9),dtype=int)

def check():
    try:
        for i in range(81):
            tableBuf[i//9][i%9]=int(value[i].get())
            if(tableBuf[i//9][i%9]<1 or tableBuf[i//9][i%9]>9):
                raise  ValueError
        flag=testWholeTable()
        if flag:
            messagebox.showinfo('消息框', '正确')
        else:
            messagebox.showinfo('消息框', '错误')
        
    except ValueError :
        messagebox.showinfo('消息框', '无效')
        
    pass

def next():
    data[0]=np.random.permutation([1,2,3,4,5,6,7,8,9])
    choice=np.random.choice(144)
    for i in range(8):
        for j in range(9):
            data[i+1][j]=data[0][(j + changelist[choice][i+1]) % 9]
    for i in range(3):
        for j in range(3):
            choice=np.random.choice(9,replace=False,size=(5,))
            for k in choice:
                data[3*i+k//3][3*j+k%3]=0
    refresh()

def refresh():
    for i in range(81):
        entry[i]["state"]='disabled' if data[i//9][i%9]!=0 else 'normal'
        value[i].set(str(data[i//9][i%9])if data[i//9][i%9]!=0 else "")
    pass


def testWholeTable():		
    list=np.ones((10,))
    flag = True
    for i in range(81):			
        searchAvalibleNumber(i // 9, i % 9, list)
        if list[tableBuf[i // 9][i % 9]] != 1:				
            flag = False
            break    
    return flag
		
def searchAvalibleNumber( x,  y,  list):
    list[0:10]=1
    for i in range(9): 
        if(i!=y):
            list[tableBuf[x][i]]=  list[tableBuf[x][i]]-1 
    for i in range(9): 
        if(i!=x):
            list[tableBuf[i][y]]= list[tableBuf[i][y]]-1
    bigx = x // 3
    bigy = y // 3
    for i in range(3):
        for j in range(3):
            if((bigx * 3 + i)!=x or (bigy * 3 + j)!=y):
                list[tableBuf[bigx * 3 + i][bigy * 3 + j]]=list[tableBuf[bigx * 3 + i][bigy * 3 + j]]-1
    for i in range(10):
        list[i] = 1 if list[i] == 1 else 0
    



data=np.array(
[[0, 1, 2, 4, 5, 6, 7, 8, 9,],
[4, 5, 6, 7, 8, 9, 3, 1, 2,],
[7, 8, 9, 3, 1, 2, 4, 5, 6,],
[1, 2, 4, 5, 6, 7, 8, 9, 3,],
[5, 6, 7, 8, 9, 3, 1, 2, 4,],
[8, 9, 3, 1, 2, 4, 5, 6, 7,],
[2, 4, 5, 6, 7, 8, 9, 3, 1,],
[6, 7, 8, 9, 3, 1, 2, 4, 5,],
[9, 3, 1, 2, 4, 5, 6, 7, 8,],])

#root = tk()
root = Tk()
line = []
for fm in range(9):
    #注意这个创建Frame的方法与其它创建控件的方法不同，第一个参数不是root
    line.append(Frame())
entry=[]
value=[]

ft = tkFont.Font(family='Fixdsys', size=20, weight=tkFont.BOLD)
for i in range(9):
    for j in range(9):
        e = StringVar()
        value.append(e)
        entry.append(Entry( line[i], width = 2,textvariable=e ,font=ft,state='disabled' if data[i][j]!=0 else 'normal'))
        entry[9*i+j].pack(side='left')
        e.set(str(data[i][j])if data[i][j]!=0 else "") 
    line[i].pack()
Button(root, text ="check", command = check).pack()
Button(root, text ="next", command = next).pack()
next()
root.mainloop()


