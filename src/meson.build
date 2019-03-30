pong_sources = [
    'difficulty.c',
    'logic.c',
    'paddles.c',
    'pong.c',
    'screen.c'
    ]

ncurses_dep = dependency('ncurses')

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

executable('pong',
    sources : pong_sources,
    install : true,
    dependencies : [ncurses_dep, m_dep]
    )
