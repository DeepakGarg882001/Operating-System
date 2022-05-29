import os
userList = {'AJ' : '12', 'BJ': '23', 'CJ': '34'}
userDirectories = {'AJ' : 'TestingAJ', 'BJ': 'TestingBJ', 'CJ': 'TestingCJ'}

def callFileMethods(user):
    directory = userDirectories.get(user)
    print(f"Welcome {user}, name of directory is {directory}\n")
    exit = 0
    while exit == 0 :
        location = "C:\AJ\College-Work\Sem-6\OS-LAB\Assignment-4\\" + directory
        currDirectory = os.listdir(f'./{directory}')
        print("\nWhat do you want to perform on this directory:- \n") 
        print(" 1. Display Files\t2. Create File\t3. Search File \t 4.Delete File \t 5.Rename File \t 6.Switch users \t0. Shutdown\n")
        userChoice = int(input("Enter your choice -- "))
        
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



        elif(userChoice == 6):
            exit = 1
            print("\nTaking your leave Good Bye 😀\n")
            login()
            break
        elif(userChoice == 0):
            exit = 1
            print("\nTaking your leave Good Bye 😀\n")
            break
        else:
            print("Please enter a number between 0 to 6")


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