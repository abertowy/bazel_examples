# Bazel docs

1. Bazel docs
    - Rules: https://bazel.build/extending/rules#output-attributes
    - Rules Tutorial: https://bazel.build/rules/rules-tutorial
    - C++ and Bazel: https://docs.bazel.build/versions/2.0.0/bazel-and-cpp.html

2. Bazel queries - links
    - https://gist.github.com/natlownes/f34aef5dabc37e645f8b8dc8892e80b2
    - https://docs.bazel.build/versions/main/query.html
    - https://docs.bazel.build/versions/main/query-how-to.html

3. GH repos
    - https://github.com/bazelbuild/bazel.git
    - https://github.com/bazelbuild/examples.git
    - https://github.com/limdor/presentations
    - https://github.com/limdor/bazel-examples
    - https://github.com/sengelha/practical_bazel_examples
    - https://github.com/bmustiata/bazel-samples.git

4. Bazel queries - examples
    - all targets from current folder, subfolders also included  
        `path> bazel query ...`  
    - all targets from particular folder  
        `bazel query //main:all`
    - list of targets with type (like cc_test, cc_binary etc)  
        ```
        bazel query 'kind(rule, ...)' --output label_kind #current folder with subfolders
        bazel query 'kind(rule, main:*)' --output label_kind #particular subfolder
        ```
    - list of dependency  
        ```
        bazel query --noimplicit_deps "deps(//folder:mytarget)"
        bazel query "deps(//folder:mytarget)" #Bazel's services dependency included
        ```
    - export dependencies to svg-picture (prereq.: graphviz should be installed, https://graphviz.org/download/)  
        ```
        sudo apt-get install graphviz
        bazel query --noimplicit_deps 'deps(//folder:target)' --output graph | dot -Tsvg > ./output.svg
        ```
    - rebuild the particular target (https://stackoverflow.com/questions/59095711/how-to-force-rebuild-a-package-in-bazel-to-measure-build-time):  
        `bazel build --action_env=STUB=$(date -Ins) :mytarget`

5. Graphviz: https://graphviz.org/Gallery/directed/bazel.html

6. Writing Bazel rules: data and runfiles: https://jayconrod.com/posts/108/writing-bazel-rules--data-and-runfiles
