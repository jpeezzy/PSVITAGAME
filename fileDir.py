from os import listdir
from os.path import isfile, join
def getSpriteFiles(path, substringName):
    onlyfiles = [f for f in listdir(path) if isfile(join(path, f))]
    finalFiles = []
    #print(onlyfiles)
    #print(len(onlyfiles))
    for i in range (0, len(onlyfiles)):
        if substringName in onlyfiles[i]:
            finalFiles.append(onlyfiles[i])
    return sorted(finalFiles)

def sortToText(fileList, path, fileName):
    f = open(fileName, 'a')
    if not path.endswith('/'):
        path+= '/'
    print(path)
    for fName in fileList:
        text = "FILE " + path + fName
        text = text + " " + path + fName+'\n'
        #print(text)
        f.write(text)
    

if __name__ == "__main__":
    mypath = "sce_sys/images/sprites/HobbesStartup"
    #print(onlyfiles)
    #print(len(onlyfiles))
    finalFiles = getSpriteFiles(mypath, "effect")
    sortToText(finalFiles, mypath, "hobbesStartup.txt")
    mypath = "sce_sys/images/sprites/Hobbes/blink/frame_0/"
    finalFiles = getSpriteFiles(mypath, "")
    sortToText(finalFiles, mypath, "hobbesSprite.txt")
    print(finalFiles)
