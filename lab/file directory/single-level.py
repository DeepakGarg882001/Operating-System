import os
import time

currDirectory = os.listdir('./Testing')

print("Welcome, You are in Single-level Directory and name of directory is Testing\n")
exit = 0
while exit == 0 :
    print("\nWhat do you want to perform on this directory:- \n") 
    print(" 1. Display Files\t2. Create File\t3. Search File \t 4.Delete File \t 5.Rename File \t0. Exit\n")
    userChoice = int(input("Enter your choice -- "))
    location = "/home/life/D : Drive/learning/Operating System/lab/file directory/Testing"
    
    if(userChoice == 1):
        print("Testing Directory contains following files: \n")
        print(currDirectory)


    elif(userChoice == 2):
        fileName = input("Enter the file name (with extension) you want to create : ")
        filePath = os.path.join(location, fileName)
        if os.path.exists(filePath):
            print("Oops! The file already exists 😐")
        else:
            open(filePath, "x")
            print("\nFile created successfully 😀\n")

        
    elif(userChoice == 3):
        fileName = input("Enter the file name (with extension) you are looking for : ")
        filePath = os.path.join(location, fileName)
        if os.path.exists(filePath):
            print("\nFile exists 😀\n")
        else:
            open(filePath, "x")
            print("Oops! The file doesn't exist 😐")
        

    elif(userChoice == 4):
        fileName = input("Enter the file name (with extension) you want to delete : ")
        filePath = os.path.join(location, fileName)
        if os.path.exists(filePath):
            os.remove(filePath)
            print("\nFile deleted successfully 😀\n")
        else:
            print("Oops! The file does not exist 😐")


    elif(userChoice == 5):
        fileName = input("Enter the file name (with extension) you want to rename : ")
        filePath = os.path.join(location, fileName)
        if os.path.exists(filePath):
            newFileName = input("What you want to name it (with extension) : ")
            newFilePath = os.path.join(location, newFileName)
            os.rename(filePath, newFilePath)
            print("\nFile renamed successfully 😀\n")
        else:
            print("Oops! The file does not exist 😐")
            
    elif(userChoice == 0):
        exit = 1
        print("\Taking your leave Good Bye 😀\n")
        break
    else:
        print("Please enter a number between 0 to 5")


