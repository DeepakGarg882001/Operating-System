import os
import shutil

userList = {'AJ' : '12', 'BJ': '23', 'CJ': '34'}
userDirectories = {'AJ' : 'TestingAJ', 'BJ': 'TestingBJ', 'CJ': 'TestingCJ'}

def callFileMethods(user):
    directory = userDirectories.get(user)
    preTraverse = []
    location = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\\" + directory
    sharedFolderLoc = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\Shared\\" + directory
    currLocation = location
    exit = 0
    while exit == 0 :
        print("\nWhat do you want to perform on this directory:- \n") 
        print(" 1. Display Files and Folders\t2. Create File\t3. Search File \t 4.Delete File \t 5.Rename File \n 6. Create Folder \t 7. Rename Folder \t 8. Delete Folder \t 9. Go to Home Directory \t 10. View Globally Shared Files \t 11. View Locally Shared Files  \t 12. Switch User \t 0. Exit\n")
        userChoice = int(input("Enter your choice -- "))
        

        if(userChoice == 1):
            print("Directory contains following files and sub-directories: \n")
            currDirectory = os.listdir(currLocation)
            print(currDirectory)
            sub = input("Do you want to traverse any sub-directory (y for YES / any other key for NO) : ").lower()
                     
            if sub == "y" : 
                subDirName = input("Enter the name of the sub-directory you want to traverse : ")
                subFiles = os.listdir(os.path.join(currLocation, subDirName))
                print("This directory contains following files and sub-directories:\n")
                print(subFiles)
                preTraverse.append(currLocation)
                currLocation = os.path.join(currLocation, subDirName)

            else:
                if(currLocation != location):
                    goBack = input("Do you want to go to the parent directory (y for YES / any other key for NO) :  ")
                    
                    if goBack == 'y':
                        currLocation = preTraverse[-1]
                        preTraverse.pop(-1)
                        print("Successfully traversed to parent folder")
                                  

        elif(userChoice == 2):
            fileName = input("Enter the file name (with extension) you want to create : ")
            filePath = os.path.join(currLocation, fileName)
            sharedFile = input("Do you want to share this file with other users ?  (y / n)").lower()
            if(sharedFile == 'y'):
                sharedFilePath = os.path.join(sharedFolderLoc, fileName)
                if os.path.exists(sharedFilePath):
                    ("Oops! The file with this name is already shared!!")
                else:
                    open(sharedFilePath, "x")
                    print("\nFile shared successfully \n")
            if os.path.exists(filePath):
                print("Oops! The file already exists!!")
            else:
                open(filePath, "x")
                print("\nFile created successfully \n")

            
        elif(userChoice == 3):
            fileName = input("Enter the file name (with extension) you are looking for : ")
            filePath = os.path.join(currLocation, fileName)
            if os.path.exists(filePath):
                print("\nFile exists \n")
            else:
                open(filePath, "x")
                print("Oops! The file doesn't s!!")
            

        elif(userChoice == 4):
            fileName = input("Enter the file name (with extension) you want to delete : ")
            filePath = os.path.join(currLocation, fileName)
            if os.path.exists(filePath):
                os.remove(filePath)
                print("\nFile deleted successfully \n")
            else:
                print("Oops! The file does not s!!")


        elif(userChoice == 5):
            fileName = input("Enter the file name (with extension) you want to rename : ")
            filePath = os.path.join(currLocation, fileName)
            if os.path.exists(filePath):
                newFileName = input("What you want to name it (with extension) : ")
                newFilePath = os.path.join(currLocation, newFileName)
                os.rename(filePath, newFilePath)
                print("\nFile renamed successfully \n")
            else:
                print("Oops! The file does not s!!")


        elif(userChoice == 6):
            folderName = input("Enter the folder name you want to create : ")
            folderPath = os.path.join(currLocation, folderName)

            if os.path.exists(folderPath):
                print("Oops! The folder already exists!!")
            else:
                os.mkdir(folderPath)
                print("\nFolder created successfully \n")
            

        elif(userChoice == 7):
            folderName = input("Enter the folder name you want to rename : ")
            folderPath = os.path.join(currLocation, folderName)
            if os.path.exists(folderPath):
                newFolderName = input("What you want to name it (with extension) : ")
                newFolderPath = os.path.join(currLocation, newFolderName)
                os.rename(folderPath, newFolderPath)
                print("\nFolder renamed successfully \n")
            else:
                print("Oops! The folder does not s!!")


        elif(userChoice == 8):
            folderName = input("Enter the folder name you want to delete : ")
            folderPath = os.path.join(currLocation, folderName)
            if os.path.exists(folderPath):
                shutil.rmtree(folderPath)
                print("\nFolder deleted successfully \n")
            else:
                print("Oops! The folder does not s!!")


        elif(userChoice == 9):
            currLocation = location


        elif(userChoice == 10):
            print("Directory contains following files\n")
            globalSharedFolderLoc = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\Shared\\"
            allFiles = []
            for user in os.listdir(globalSharedFolderLoc):
                userFolder = []
                for userFile in os.listdir(os.path.join(globalSharedFolderLoc,user)):
                    userFolder.append(userFile)
                allFiles.append(userFolder)
            print(allFiles)

            takeCopy = input("Do you want to take a copy of any shared file into your local system (y for YES / any other key for NO) : ").lower()
            if takeCopy == "y" : 
                copyFileName = input("Which file (with extension) : ")
                userIndex = -1
                for i, item in enumerate(allFiles):
                    if copyFileName in item:
                        userIndex = i
                userFold = ''
                if(userIndex >= 0):
                    if(userIndex == 0):
                        userFold = "TestingAJ"
                    elif(userIndex == 1):
                        userFold = "TestingBJ"
                    elif(userIndex == 2):
                        userFold = "TestingCJ"
                else:
                    print("No file with this name found")
                fileLocation = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\Shared\\" + userFold
                sharedFileSrc = os.path.join(fileLocation, copyFileName)
                completePath = os.path.join(location, "shared")
                print(completePath)
                shutil.copy(sharedFileSrc, completePath)
                print("File copied to your local shared folder")

        elif(userChoice == 11):
            globalSharedFolderLoc = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\Shared\\"
            print("Local Shared Directory contains following files\n")
            localSharedFolderLoc = os.path.join(location, "shared")
            print(os.listdir(localSharedFolderLoc))
            updateFile = input("Do you want to update any shared file (this will overwrite global file) (y for YES / any other key for NO) : ").lower()
            if updateFile == "y" : 
                updateFileName = input("Which file (with extension) : ")
                allFiles = []
                for user in os.listdir(globalSharedFolderLoc):
                    userFolder = []
                    for userFile in os.listdir(os.path.join(globalSharedFolderLoc,user)):
                        userFolder.append(userFile)
                    allFiles.append(userFolder)
                userIndex = -1
                for i, item in enumerate(allFiles):
                    if updateFileName in item:
                        userIndex = i
                userFold = ''
                if(userIndex >= 0):
                    if(userIndex == 0):
                        userFold = "TestingAJ"
                    elif(userIndex == 1):
                        userFold = "TestingBJ"
                    elif(userIndex == 2):
                        userFold = "TestingCJ"
                else:
                    print("No file with this name found")
                globalfileLocation = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\Shared\\" + userFold
                localSharedFileSrc = os.path.join(location, "shared", updateFileName)
                shutil.copy(localSharedFileSrc, globalfileLocation)
                print("File updated globally")

        elif(userChoice == 12):
            exit = 1
            print("\nTaking your leave Good Bye 😀\n")
            login()
            break
        elif(userChoice == 0):
            exit = 1
            print("\nTaking your leave Good Bye 😀\n")
            break
        else:
            print("Please enter a number between 0 to 10")


def login():
    loggedIn = False
    while(loggedIn == False):
        print("USERS AVAILABLE ON THIS SYSTEM\n")
        for i in userList.keys():
            print(f"{i}")
        user = input("\nChoose Username to login : ")
        if user in userList.keys():
            userPass = input(f"Enter password for {user} : ")
            if(userPass == userList.get(user)):
                loggedIn = True
                callFileMethods(user)
            else:
                print("\nWrong Password ☹, Try Again")
login()
