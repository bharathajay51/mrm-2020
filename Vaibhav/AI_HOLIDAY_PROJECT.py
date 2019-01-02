import cv2
import os
from random import shuffle
import tqdm
import matplotlib.pyplot as plt
import tensorflow as tf
import tflearn

train_directory = 'C:/Users/Desktop/Train' #path of train data folder
test_directory = 'C:/Users/Desktop/Test'   #path of test data folder 
image_size = 50 # image size = 50 * 50 pixels
learning_rate = 0.001
MODEL_NAME = 'AI HOLIDAY PROJECT'

def label_img(img):
    img_label = img.split('.')[-3] #img = name(cat or dog).num.jpg, img.split('.')[-3] gives 'dog' or 'cat' as the output 
    if(img_label == 'cat'):
        return [1,0]           # returns [1,0] if cat and returns [0,1] if dog
    elif(img_label == 'dog'):
        return [0,1]

def train_neural_network():
    training_data = [] #empty list which will be appended with img and label
    for img in tqdm(os.listdir(train_directory)):
        label = label_img(img)
        path = os.path.join(train_directory,img)
        img = cv.resize(cv.imread(path,IMREAD_GRAYSCALE),(image_size,image_size)) #conversion into grayscale
        training_data.append([np.array(img),np.array(label)])
    shuffle(training_data)
    np.save('training_data.npy',training_data)
    return training_data

train_data = train_neural_network()

from tflearn.layers.conv import max_pool_2d,conv_2d
from tflearn.layers.core import input_data,dropout,fully_connected
from tflearn.layers.estimator import regression

X_input = input_data(shape=[None,image_size,image_size,1],name='inputs')

conv1 = conv_2d(X_input,40,5,activation='relu') # 40 filters , strides = 5
pool1 = max_pool_2d(conv1,5) # pool size = 5 , by default strides = pool size

conv2 = conv_2d(pool1,80,5,activation='relu') # 80 filters 
pool2 = max_pool_2d(conv2,5)

conv3 = conv_2d(pool2,160,5,activation='relu') # 160 filters
pool3 = max_pool_2d(conv3,5)

conv4 = conv_2d(pool3,80,5,activation='relu') # 80 filters
pool4 = max_pool_2d(conv4,5)

conv5 = conv_2d(pool4,40,5,activation='relu') #40 filters
pool5 = max_pool_2d(conv5,5)

fc1 = fully_connected(pool5,1600,activation='relu')  # 1600 neurons 

fc2 = fully_connected(fc1,2,activation='softmax') # 2 output neurons 

reg = regression(fc2,optimizer='adam',learning_rate=learning_rate,loss='categorical_crossentropy')

model = tflearn.DNN(reg)

train = train_data[:-500]
test = train_data[-500:]

X_train = [i[0] for i in train].reshape(-1,image_size,image_size,1)
Y_train = [i[1] for i in train]

X_test = [i[0] for i in test].reshape(-1,image_size,image_size,1)
Y_test = [i[1] for i in test]

model.fit(X_train,Y_train,n_epochs=5,validation_set=(X_test,Y_test),snapshot_step=500,show_metric=True,run_id=MODEL_NAME)

def process_test_data():
    testing_data=[]
    for img in tqdm(os.listdir(test_directory)):
        img_number = img.split('.')[0]
        path = os.path.join(test_directory)
        img = cv2.resize(cv2.imread(path,IMREAD_GRAYSCALE),(image_size,image_size))
        testing_data.append([np.array(img),np.array(img_number)])
    np.save('testing_data.npy',testing_data)
    return testing_data

test_data = process_test_data()

fig = plt.figure()

for number,data in enumerate(test_data[:30]):

    img_num = data[0]
    img_data = data[1]

    y = fig.add_subplot(5,6,number+1)

    p = image_data
    data = image_data.resize(image_size,image_size,1)
    predict = model.predict([data])[0]

    if(np.argmax(predict) == 0):
        img_label = 'cat'
    else:
        img_label = 'dog'

    y.imshow(p,cmap='gray')
    plt.title(img_label)

plt.show()

#acc - 82.93% , validation accuracy - 81.6%




        







