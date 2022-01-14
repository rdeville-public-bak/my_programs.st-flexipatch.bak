<!-- markdownlint-disable MD041 -->
{% set curr_repo=subs("TODO") %}

<!-- BEGIN MKDOCS TEMPLATE -->
<!--
WARNING, DO NOT UPDATE CONTENT BETWEEN MKDOCS TEMPLATE TAG !
Modified content will be overwritten when updating
-->

# Licenses

<!-- END MKDOCS TEMPLATE -->

## `st` LICENSE: MIT/X Consortium License

MIT/X Consortium License

© 2014-2020 Hiltjo Posthuma <hiltjo at codemadness dot org>
© 2018 Devin J. Pohly <djpohly at gmail dot com>
© 2014-2017 Quentin Rameau <quinq at fifth dot space>
© 2009-2012 Aurélien APTEL <aurelien dot aptel at gmail dot com>
© 2008-2017 Anselm R Garbe <garbeam at gmail dot com>
© 2012-2017 Roberto E. Vargas Caballero <k0ga at shike2 dot com>
© 2012-2016 Christoph Lohmann <20h at r-36 dot net>
© 2013 Eon S. Jeon <esjeon at hyunmu dot am>
© 2013 Alexander Sedov <alex0player at gmail dot com>
© 2013 Mark Edgar <medgar123 at gmail dot com>
© 2013-2014 Eric Pruitt <eric.pruitt at gmail dot com>
© 2013 Michael Forney <mforney at mforney dot org>
© 2013-2014 Markus Teich <markus dot teich at stusta dot mhn dot de>
© 2014-2015 Laslo Hunhold <dev at frign dot de>

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

## Other files

Some files are not part of [st](https://st.suckless.org/), neither
[st-flexipatch](https://github.com/bakkeby/st-flexipatch). These files are
mainly my `st` configuration files (`patches.h` and `config.h`) and my
documentation and developpement related files (like `.editorconfig`,
`pyproject.toml`, `docs/`, etc) and are under dual licensing:

  * [MIT License](#mit-license)
  * [Beer-Ware License](#the-beer-ware-license)

## MIT License

{{ date_copyright }}

<!-- markdownlint-disable MD032 -->
{% for i_maintainer in curr_repo.maintainers %}
  * [{{ i_maintainer.name }}](mailto:{{ i_maintainer.mail }})
{% endfor %}
<!-- markdownlint-enable MD032 -->

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## The Beer-Ware License

Following maintainers worked on this project:

<!-- markdownlint-disable MD032 -->
{% for i_maintainer in curr_repo.maintainers %}
  * [{{ i_maintainer.name }}](mailto:{{ i_maintainer.mail }})
{% endfor %}
<!-- markdownlint-enable MD032 -->

As long as you retain this notice you can do whatever you want with this stuff.

If we meet some day, and you think this stuff is worth it, you can buy us a
beer in return.
