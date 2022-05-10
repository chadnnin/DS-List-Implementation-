import subprocess

SUCCESS_MESSAGE = "All Test Passed!"

def testAdd():
    """Test add()"""
    # Create a subprocess to run the students make file to ensure it compiles 
    fib = subprocess.Popen("./Lists.exe arraylist add".split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output = fib.stdout.read().strip().decode('utf-8')
    fib.kill()

    # Standard unit test case with an associated error message
    print(output)
    print(SUCCESS_MESSAGE)
    print(output == SUCCESS_MESSAGE)
    fib.terminate()

testAdd()
