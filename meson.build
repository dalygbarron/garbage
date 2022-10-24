project('garbage', 'cpp', default_options : ['c_std=c11', 'cpp_std=c++11'])

#add_project_arguments('-fsanitize=address', language : 'cpp')
#add_project_link_arguments('-fsanitize=address', language : 'cpp')

core_src = [
  'core/Bongo.cc',
  'core/Map.cc',
  'core/Vector.cc',
  'core/Rect.cc',
  'core/Dude.cc',
  'core/Entity.cc',
  'core/Game.cc',
  'core/Action.cc',
  'core/Util.cc',
  'core/RenderParams.cc'
]
curses_src = [
  'curses/main.cc'
]
cc = meson.get_compiler('cpp')
curses_deps = [
  cc.find_library('ncurses', dirs: ['/usr/local/opt/ncurses/lib']),
  cc.find_library('menu', dirs: ['/usr/local/opt/ncurses/lib']),
]
core_dir = include_directories('core')
core = library('garbage_core', core_src)
executable(
  'garbage-curses',
  curses_src,
  link_with: core,
  dependencies: curses_deps,
  include_directories: core_dir
)