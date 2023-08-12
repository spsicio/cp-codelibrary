#set page(width: 29.7cm, height: 21.0cm)
#set text(font: "LXGW WenKai", size: 11pt)
#set heading(numbering: "1.1")
#show heading.where(level: 1): it => block[
  #text(size: 16pt)[*#it*]
  #line(length: 100%, stroke: 0.5pt)
]
#show heading.where(level: 2): it => block[#text(size: 12pt)[*#it*]]
#show raw: it => text(font: ("Fira Code", "LXGW WenKai Mono"), size: 7pt)[#it]

#align(
  center + horizon,
  [
    #text(32pt)[*SP-51 C-10: Code Library*]
    #image("pic/Rainbow.png", width: 30%)
  ]
)
#pagebreak(weak: true)

#set page(numbering: "1")
#show outline: it => columns(2, it)
#outline(title: "目錄", indent: auto)
#pagebreak(weak: true)

#show: rest => columns(2, rest)
#let description(it) = block(fill: luma(230), inset: 4pt, radius: 4pt)[#it]
#let codelib(it) = {
  for (category, dir, docs) in it {
    [= #category]
    for (title, fname, desc) in docs {
      [== #title]
      if desc != none { description(eval("[" + desc + "]")) }
      if fname != none {
        let code = read("src/" + dir + fname)
        raw(code, lang: "cpp")
      }
    }
  }
}

#codelib(yaml("codelib.yaml"))