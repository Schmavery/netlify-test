const path = require('path');

const withMDX = require('@next/mdx')();
const withTM = require('next-transpile-modules');
const withBundleAnalyzer = require('@next/bundle-analyzer')({
  enabled: process.env.ANALYZE === 'true',
});

module.exports = withTM(withBundleAnalyzer(withMDX({
  async exportPathMap() {

    let pages = {
      '/': { page: '/' },
    };

    return pages;
  },
  pageExtensions: ['jsx', 'js', 'mdx'],
  transpileModules: ['bs-platform', 'bs-css', 'bsc-stdlib-polyfill'],
  webpack(config, options) {
    config.resolve.alias['@reason'] = path.join(__dirname, 'lib', 'es6', 'src');
    config.resolve.alias['@docs'] = path.join(__dirname, 'docs');
    config.resolve.extensions.push('.bs.js');
    return config
  },
})))
