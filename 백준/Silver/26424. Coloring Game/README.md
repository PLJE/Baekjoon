# [Silver V] Coloring Game - 26424 

[문제 링크](https://www.acmicpc.net/problem/26424) 

### 성능 요약

메모리: 5928 KB, 시간: 8 ms

### 분류

수학, 그리디 알고리즘, 사칙연산

### 문제 설명

<p>John loves to play computer games. He recently discovered an interesting game. In the game there are <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-b"><mjx-c class="mjx-c1D40D TEX-B"></mjx-c></mjx-mi></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mi mathvariant="bold">N</mi></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\mathbf{N}$</span></mjx-container> cells, which are aligned in a row from left to right and are numbered with consecutive integers starting from <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>. Initially, all cells are coloured <i>white</i>. A cell is valid if it has <i>white</i> color and it does not have any adjacent <i>red</i> colored cell. On each turn, a player paints any valid cell with the <i>red</i> color. The game ends when no valid cells are present. The score of the player is equal to the number of cells they paint.</p>

<p>To master the game, John is practicing against a bot. The bot is poorly trained and it always paints the first valid cell from the left. John on the other hand is playing the game very carefully and he can choose any valid cell. The bot makes the first move and the players take turns alternately.</p>

<p>Find the <i>maximum</i> achievable score by the bot, assuming that John is playing optimally to minimize the score of his opponent.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-b"><mjx-c class="mjx-c1D413 TEX-B"></mjx-c></mjx-mi></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mi mathvariant="bold">T</mi></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\mathbf{T}$</span></mjx-container>. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-b"><mjx-c class="mjx-c1D413 TEX-B"></mjx-c></mjx-mi></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mi mathvariant="bold">T</mi></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\mathbf{T}$</span></mjx-container> test cases follow.</p>

<p>The only line of each test case contains an integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-texatom texclass="ORD"><mjx-mi class="mjx-b"><mjx-c class="mjx-c1D40D TEX-B"></mjx-c></mjx-mi></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mi mathvariant="bold">N</mi></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\mathbf{N}$</span></mjx-container> representing the number of cells in the game.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container> is the test case number (starting from 1) and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container> is the <i>maximum</i> achievable score by the bot given that John is playing optimally.</p>

