from flask import Flask, render_template, jsonify
import math
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html',title='Home')

@app.route('/api/getData')
def getData():
    pir_list = []
    motion_list = []
    ultrasonic_list = []
    with open('received_data.txt', 'r') as file:
        for line in file:
            values = line.strip().split(',')
            pir_list.append(float(values[2]))
            motion_list.append(float(values[1]))
            ultrasonic_list.append(float(values[0]))
    last = 0
    for i in range(1,len(ultrasonic_list)):
        if math.floor(ultrasonic_list[i-1]) == math.floor(ultrasonic_list[i]):
            last+=1
        else:
            last=1
    print(last)
    maxi = 0
    cnt = 1
    for i in range(0, len(ultrasonic_list)):
        if i>0 and ultrasonic_list[i-1]==ultrasonic_list[i]:
            cnt+=1
        maxi = max(maxi, cnt)
    print(maxi)
    return jsonify({'pir': pir_list[-10:], 'motion': motion_list[-10:], 'ultrasonic': ultrasonic_list[-10:],'last':last,'maxi':maxi})


# Enable debug mode
app.debug = True

# Your Flask app routes and other configurations go here

if __name__ == '__main__':
    app.run(debug=True)