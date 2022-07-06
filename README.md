# cpp-study: collection of modern C++ programs.

This project follows the Pitchfork Layout (PFL) and reproduces some of its information here.

https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#intro.files


build/

    A special directory that should not be considered part of the source of the project. 
    Used for storing ephemeral build results. 
    Must not be checked into source control. 
    If using source control, must be ignored using source control ignore-lists.

src/

    Main compilable source location. must be present for projects with compiled components that do not use submodules.
    In the presence of include/, also contains private headers.

include/

    Directory for public headers. may be present. may be omitted for projects that do not distinguish between private/public headers. may be omitted for projects that use submodules.
tests/

    Directory for tests.

examples/

    Directory for samples and examples.

external/

    Directory for packages/projects to be used by the project, but not edited as part of the project.

extras/

    Directory containing extra/optional submodules for the project.

data/

    Directory containing non-source code aspects of the project. This might include graphics and markup files.

tools/

    Directory containing development utilities, such as build and refactoring scripts

docs/

    Directory for project documentation.

libs/

    Directory for main project submodules.
