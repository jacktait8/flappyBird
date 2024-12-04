# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt" AND EXISTS "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt" AND
  "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt" IS_NEWER_THAN "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt")
  message(VERBOSE
    "Avoiding repeated git clone, stamp file is up to date: "
    "'C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

# Even at VERBOSE level, we don't want to see the commands executed, but
# enabling them to be shown for DEBUG may be useful to help diagnose problems.
cmake_language(GET_MESSAGE_LOG_LEVEL active_log_level)
if(active_log_level MATCHES "DEBUG|TRACE")
  set(maybe_show_command COMMAND_ECHO STDOUT)
else()
  set(maybe_show_command "")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'C:/Users/jakes/source/repos/flappy/build/_deps/box2d-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/erincatto/box2d" "box2d-src"
    WORKING_DIRECTORY "C:/Users/jakes/source/repos/flappy/build/_deps"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(NOTICE "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/erincatto/box2d'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"
          checkout "v2.4.1" --
  WORKING_DIRECTORY "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v2.4.1'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-src"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'C:/Users/jakes/source/repos/flappy/build/_deps/box2d-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitinfo.txt" "C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'C:/Users/jakes/source/repos/flappy/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/box2d-populate-gitclone-lastrun.txt'")
endif()
