node {

    sh "echo \$PWD"

    stage('Preparation') { 
        // Get some code from a GitHub repository
        git 'https://github.com/flingengine/FlingEngine.git'
        sh "./Init.sh"
    }

    stage('Build GCC') {
        echo 'Building with GCC...'
        sh "g++ --version"

        sh "export CC=/usr/local/bin/gcc"
        sh "export CXX=/usr/local/bin/g++"

        sh "./Init.sh"
        sh "build"
        sh "make"
    }

    stage('Build Clang') {
        echo 'Building with Clang...'
        sh "clang++ --version"

        sh "export CC=/usr/local/bin/clang"
        sh "export CXX=/usr/local/bin/clang++"

        sh "./Init.sh"
        sh "build"
        sh "make"
    }
}
