project('garbage', 'cpp')
cc = meson.get_compiler('cpp')
core_src = [
  'core/Bongo.cc'
]
curses_src = [
  'curses/main.cc'
]
curses_deps = [
  cc.find_library('ncurses', dirs: ['/usr/local/opt/ncurses/lib']),
  cc.find_library('menu', dirs: ['/usr/local/opt/ncurses/lib']),
]

core = library('garbage_core', core_src)
executable(
  'garbage-curses',
  curses_src,
  link_with: core,
  dependencies: curses_deps
)
