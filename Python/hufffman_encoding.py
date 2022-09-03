from bz2 import decompress
import heapq
import os
from importlib.resources import path

class BinaryTreeNode:
    def __init__(self,val,freq):
        self.value = val
        self.freq=freq
        self.left = None
        self.right = None
    def __lt__(self,other):
        return self.freq < other.freq
    def __le__(self,other):
        return self.freq == other.freq

class HuffmanCoding:

    def __init__(self,path):
        self.path = path
        self.__heap=[]
        self.__codes = {}
        self.__reversecodes={}

    def __make_frequenct_dict(self,text):
        freq_dict = {}
        for char in text:
            if char in freq_dict:
                freq_dict[char]+=1
            else:
                freq_dict[char]=1
        return freq_dict
    
    def __buildHeap(self,freq_dict):
        #heap will store each binary tree Node
        #binary tree node has value , freq , left and right
        for key,val in freq_dict.items():
            node=BinaryTreeNode(key,val)
            heapq.heappush(self.__heap,node)
            pass

    def __buildTree(self):
        while(len(self.__heap)>1):
            b1 = heapq.heappop(self.__heap)
            b2 = heapq.heappop(self.__heap)
            k = b1.freq+b2.freq
            newNode = BinaryTreeNode(None,k)
            newNode.left = b1
            newNode.right = b2
            heapq.heappush(self.__heap,newNode)
        return
    
    def __buildCodesHelper(self,root,curr_bits):

        if root is None:
            return
        if root.value is not None:
            self.__codes[root.value]=curr_bits
            self.__reversecodes[curr_bits]=root.value
            return
        self.__buildCodesHelper(root.left,curr_bits+"0")
        self.__buildCodesHelper(root.right,curr_bits+"1")

        
        pass
    def __buildCodes(self):
        root = heapq.heappop(self.__heap)
        self.__buildCodesHelper(root,"")
    
    def __encoder(self,text):
        ans =""
        for char in text:
            ans+=self.__codes[char]
        return ans

    def __getPaddedEncodedText(self,encoded_text):
        padded_amt = 8-(len(encoded_text)%8)
        for i in range(padded_amt):
            encoded_text+='0'
        padded_info = "{0:08b}".format(padded_amt)
        encoded_text=padded_info+encoded_text
        return encoded_text
    
    def __getBytesArray(self,padded_encoded_text):
        arr =[]
        for i in range(0,len(padded_encoded_text),8):
            byte = padded_encoded_text[i:i+8]
            #taking base to be 2
            arr.append(int(byte,2))
        return arr
    def compress(self):
        #read text from file
        file_name,file_extension = os.path.splitext(self.path)
        output_path = file_name + ".bin"
        with open(self.path,"r+") as file,open(output_path,'wb') as output:
            text = file.read()
            text = text.rstrip()
            #make frequency dictionary using the text
            freq_dict = self.__make_frequenct_dict(text)
            #build heap for two node of minimum freq fron the freq dictionary
            self.__buildHeap(freq_dict)
            #construct the binary tree
            self.__buildTree()
            #construct codes from the binary tree for each letter
            self.__buildCodes()
            #create encoded text using the codes
            encoded_text = self.__encoder(text)
            #first 8 bits will represent how much we have padded
            #pad this encoded text
            padded_encoded_text = self.__getPaddedEncodedText(encoded_text)
            bytes_array = self.__getBytesArray(padded_encoded_text)
            #put this encoded text in to the binary file
            final_bytes = bytes(bytes_array)
            #return binary file as output
            output.write(final_bytes)
            print("Compressed")
            return output_path
    def __removePadding(self,text):
        padded_info = text[:8]
        extra_padding = int(padded_info,2)
        text = text[8:]
        text_after_padding_removed=text[:-1*extra_padding]
        return text_after_padding_removed
    def __decode(self,text):
        decodedtext = ""
        temp =""
        for char in text:
            temp +=char
            if temp in self.__reversecodes:
                decodedtext+=self.__reversecodes[temp]
                temp=""
        return decodedtext

    def decompress(self,input_path):
        filename,file_extension = os.path.splitext(self.path)
        output_path=filename+"_decompressed"+".txt"
        with open(input_path,'rb') as file,open(output_path,'w') as output:
            bit_string = ""
            byte = file.read(1)
            while byte:
                byte = ord(byte)
                bits = bin(byte)[2:].rjust(8,'0')
                bit_string+=bits
                byte=file.read(1)
            actual_text = self.__removePadding(bit_string)
            decompressed_text = self.__decode(actual_text)
            output.write(decompressed_text)
        return



def main():
    path = "/Users/tanmay/Desktop/DSA/CPP/Python/sample.txt"
    h = HuffmanCoding(path)
    output_path = h.compress()
    h.decompress(output_path)
  
  
# Using the special variable 
# __name__
if __name__=="__main__":
    main()